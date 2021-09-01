-module(esPrimo).
-export([esPrimo/2, sec/1, sumaPrimo/3, conc/1, cPrimo/3]).

esPrimo(N,I) ->
	R = math:sqrt(N),
	if
	I > R -> true;
	N rem I == 0 -> false; %no es primo true -> esPrimo(N, I+1)
end.

sumaPrimo(L,N,S) -> if %manda de parametro el limite superior, inferior y la suma 
	N =< L ->
	P = esPrimo(N,2),
	if
		P == false -> sumaPrimo(L, N + 1, S);
		true -> sumaPrimo(L, N + 1, S + N) %es primo entonces realiza la suma end;
	end;
	true -> io:format("~p~n", [S]) %muestra la suma
end.

sec(L) ->
	T1 = time(),
	sumaPrimo(L,2,0),
	T2 = time().
% difTiempo = timer:now_diff(T2,T1),
% io:format("Tiempo: ~p~n", [difTiempo]).

cPrimo(L,N,S) -> T1 = time(), sumaPrimo(L,N,S), T2 = time().
% difTiempo = timer:now_diff(T2,T1),
% io:format("Tiempo: ~p~n", [difTiempo]).

%se parte en dos para hacerlo en paralelo
conc(N) ->
spawn(esPrimo, cPrimo, [N div 2, 2, 0]), spawn(esPrimo, cPrimo, [N, N div 2 + 1, 0]).