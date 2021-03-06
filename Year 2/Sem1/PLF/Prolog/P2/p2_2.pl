%a. Sort a list with keeping double values in resulted list. E.g.: [4 2 6 2 3 4] --> [2 2 3 4 4 6]
%insertSort(l1..ln, e) = [e], if n == 0
%                        e U l1..ln, if l1 == e
%                        e U l1..ln, if e < l1
%                        l1 U insertSort(l2..ln, e), if e > l1

insertSort([], E, [E]).
insertSort([E|T], E, [E, E|T]).
insertSort([H|T], E, [E, H|T]):- E < H.
insertSort([H|T], E, [H|R]):-
    E > H,
    insertSort(T, E, R).

%sortKeepDoubles(l1..ln) = [], if n == 0
%                          insertSort(sortKeepDoubles(l2..ln), l1),
%                          otherwise
sortKeepDoubles([], []).
sortKeepDoubles([H|T], R):-
    sortKeepDoubles(T, R1),
    insertSort(R1, H, R).

%b. For a heterogeneous list, formed from integer numbers and list of numbers, write a predicate to sort every
%sublist, keeping the doubles.
%sortHL(l1..ln) = [], if n == 0
%                 sortHL(l2..ln), if l1 is number
%                 sortKeepDoubles(l1) U sortHL(l2..ln), if l1 is list
sortHL([], []).
sortHL([H|T], [H|R]):-
    number(H),
    sortHL(T, R).
sortHL([H|T], [R1|R]):-
    is_list(H),
    sortKeepDoubles(H, R1),
    sortHL(T, R).
