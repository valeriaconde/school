-module(semantic).
-export([main/1]).

main(String) -> io:format("~p = ~p -> ~p~n", [main(String, 0), equal(String), main(String, 0) == equal(String)]).

main(String, Acum) ->
  Op = lists:member(hd(String), "+-*/="),
  if
    Op == true -> 
      case hd(String) of 
        45 -> add_subs(String, Acum);
        43 -> add_subs(String, Acum);
        42 -> mult(tl(String), Acum);
        47 -> divs(tl(String), Acum);
        61 -> Acum
      end;
    true ->
      {H, T} = string:to_integer(String),
      main(T, H)
  end.

add_subs(String, Acum) ->
  {H, T} = string:to_integer(String),
  Acum + main(T, H).

mult(String, Acum) ->
  {H, T} = string:to_integer(String),
  main(T, H * Acum).

divs(String, Acum) ->
  {H, T} = string:to_integer(String),
  main(T, Acum / H).

equal(String) -> 
  if
    hd(String) == 61 -> {H, _} = string:to_integer(tl(String)), H;
    hd(String) == 42 -> {_, T} = string:to_integer(tl(String)), equal(T);
    hd(String) == 47 -> {_, T} = string:to_integer(tl(String)), equal(T);
    true -> {_, T} = string:to_integer(String), equal(T)
  end.