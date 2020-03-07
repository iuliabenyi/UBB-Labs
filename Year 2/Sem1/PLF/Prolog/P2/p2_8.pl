%a. Determine the successor of a number represented as digits in a list.
%append(l1..ln, e) = [e], if n == 0
%                    l1 U append(l2..ln), otherwise

append([], E, [E]).
append([H|T], E, [H|R]):-
    append(T, E, R).

%lengthL(l1..ln) = 0 , if n == 0
%                  1 + lengthL(l2..ln), otherwise
lengthL([], 0).
lengthL([_|T], R):-
    lengthL(T, R1),
    R is R1 + 1.

%reverse(l1..ln) = [], if n == 0
%                  append(reverse(l2..ln), l1), otherwise
reverseL([], []).
reverseL([H|T], R):-
    reverseL(T, R1),
    append(R1, H, R).
%sum(l1..ln, k1..km, c) = [], n = 0 and m = 0 and c = 0
%                         [1], n = 0 and m = 0 and c = 1
%                         (k1 + c) + sum([], k2..km, 0), n = 0 and b1 +
%c < 10
%                         ((k1 + c)%10) + sum([], k2..km, 1), n =0 and k1 + c > 10
%                         (l1 + k1 + c) + sum(l2..ln,k2..km, 0), l1 + k1 + c < 10
%                         ((a1+b1+c)%10) + sum(l2..ln, k2..km, 2), l1 + k1 + c >10
sum([], [], 0, []).
sum([], [], 1, [1]).
sum([], [HB|TB], C, [HBC|R]) :-
    HBC is (HB + C) mod 10,
    HBC - HB - C =:= 0,
    sum([], TB, 0, R).
sum([], [HB|TB], C, [HBC|R]) :-
    HBC is (HB + C) mod 10,
    HBC - HB - C =\= 0,
    sum([], TB, 1, R).
sum([HA|TA], [HB|TB], C, [HR|R]) :-
    HR is (HA + HB + C) mod 10,
    HR - HA - HB - C =:= 0,
    sum(TA, TB, 0, R).
sum([HA|TA], [HB|TB], C, [HR|R]) :-
    HR is (HA + HB + C) mod 10,
    HR - HA - HB - C =\= 0,
    sum(TA, TB, 1, R).

% sum_lists(l1...ln, k1...km) = l1...ln, m = 0
%	                        k1...km, n = 0
%                               reverse(sum(reverse(l1...ln),
%                        reverse(k1...km), 0)), n <= m
%                        reverse(sum(reverse(k1...km),
%                        reverse(l1...ln), 0)), otherwise

sumLists(L, [], L).
sumLists([], K, K).
sumLists(L, K, R) :-
    lengthL(L, LL),
    lengthL(K, LK),
    LL =< LK, !,
    reverseL(L, RL),
    reverseL(K, RK),
    sum(RL, RK, 0, RS),
    reverseL(RS, R).
sumLists(L, K, R) :-
    reverseL(L, RL),
    reverseL(K, RK),
    sum(RK, RL, 0, RS),
    reverseL(RS, R).

successor(L, R):- sumLists([1], L, R).

%b. For a heterogeneous list, formed from integer numbers and list of numbers, determine the successor of a
%sublist considered as a number.
%successorHL(l1..ln) = [], if n == 0
%                      l1 U successorHL(l2..ln), if l1 number
%                      successor(l1) U successorHL(l2..ln), if l1 list
successorHL([], []).
successorHL([H|T], [H|R]):-
    number(H),
    successorHL(T, R).
successorHL([H|T], [R1|R]):-
    is_list(H),
    successor(H, R1),
    successorHL(T, R).
