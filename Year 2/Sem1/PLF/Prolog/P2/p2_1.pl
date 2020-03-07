%a. Sort a list with removing the double values. E.g.: [4 2 6 2 3 4] --> [2 3 4 6]
%insertUnique(l1..ln, e) = [e], if n == 0
%                          l1..ln, if l1 == e
%                          e U l1..ln, if e < l1
%                          l1 U insertUnique(l2..ln, e), if e > l1
insertUnique([], E, [E]).
insertUnique([E|T], E, [E|T]).
insertUnique([H|T], E, [E, H|T]):-
    E < H.
insertUnique([H|T], E, [H|R]):-
    E > H,
    insertUnique(T, E, R).

%sortUnique(l1..ln) = [], if n == 0
%                     insertUnique(sortUnique(l2..ln), l1), otherwise
sortUnique([], []).
sortUnique([H|T], R):-
    sortUnique(T, R1),
    insertUnique(R1, H, R).

%b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to sort every
%sublist with removing the doubles
sortHL([], []).
sortHL([H|T], [H|R]):-
    number(H),
    sortHL(T, R).
sortHL([H|T], [R1|R]):-
    is_list(H),
    sortUnique(H, R1),
    sortHL(T, R).

