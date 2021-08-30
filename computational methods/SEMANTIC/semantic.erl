% Valeria Conde A01281637
% Daniela Garza A00829404

-module(semantic).
-export([check/1, process/0, func/1]).

check(Expression) -> io:format("~p = ~p -> ~p~n", [check(Expression, 0), ans(Expression), check(Expression, 0) == ans(Expression)]).

% F = first, R = Rest (of list)
% sum function to process sums and substractions (same thing)
sum(Expression, Cont) ->
  {F, R} = string:to_integer(Expression),
  Cont + check(R, F).

% mult function to process multiplication
mult(Expression, Cont) ->
  {F, R} = string:to_integer(Expression),
  check(R, F * Cont).

% divs function to process division
divs(Expression, Cont) ->
  {F, R} = string:to_integer(Expression),
  check(R, Cont / F).

% iterate list 
ans(Expression) -> 
  if
    hd(Expression) == 42 -> {_, R} = string:to_integer(tl(Expression)), ans(R);
    hd(Expression) == 47 -> {_, R} = string:to_integer(tl(Expression)), ans(R);
    hd(Expression) == 61 -> {F, _} = string:to_integer(tl(Expression)), F;
    true -> {_, R} = string:to_integer(Expression), ans(R)
  end.

% sends respective operation to function
check(Expression, Cont) ->
  % Ch = character
  Ch = lists:member(hd(Expression), "+-*/="),
  if
    Ch == true -> 
      case hd(Expression) of 
        42 -> mult(tl(Expression), Cont);
        43 -> sum(Expression, Cont);
        45 -> sum(Expression, Cont);
        47 -> divs(tl(Expression), Cont);
        61 -> Cont
      end;
    true ->
      {F, R} = string:to_integer(Expression),
      check(R, F)
  end.

% iterate the list of lines in the file
func([]) -> ok;
func([F|R]) ->
    spawn(anal,check,[F]),
    func(R).

% spawns process to check the validity of every expression
process() ->
  {ok, Binary} = file:read_file("input.txt"),
  Lines = string:tokens(erlang:binary_to_list(Binary), "\n"),
  spawn(anal, func, [Lines]).