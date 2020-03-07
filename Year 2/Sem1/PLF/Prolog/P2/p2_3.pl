%a. Merge two sorted lists with removing the double values
%
%merge(l1..ln, k1..km) = l1..ln, if m == 0
%                        k1..km, if n == 0
%                        k1 U merge(l1..ln, k2..km), if l1 > k1
%                        l1 U merge(l2..ln, k1..km), if l1 < k1
%                        l1 U merge(l2..ln, k2..km), if l1 == k1
merge(L, [], L).
merge([], K, K).
merge([HL|TL], [HK|TK], [HK|R]):-
    HL > HK,
    merge([HL|TL], TK, R).
merge([HL|TL], [HK|TK], [HL|R]):-
    HL < HK,
    merge(TL, [HK|TK], R).
merge([HL|TL], [HK|TK], [HL|R]):-
    HL == HK,
    merge(TL, TK, R).

%b. For a heterogeneous list, formed from integer numbers and list of numbers, merge all sublists with removing
%the double values
%mergeHL(l1..ln) = [], if n == 0
%                  mergeHL(l2..ln), if l1 and l2 number
%                  merge(l1, l2) U mergeHL(l2..ln), otherwise
mergeHL([], []).
mergeHL([H|T], R):-
    is_list(H),
    !,
    mergeHL(T, R1),
    merge(H, R1, R).
mergeHL([_|T], R):-
    mergeHL(T, R).
