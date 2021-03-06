f([], 0).
f([H|T], S) :- f(T, S1), S1<H,!,S is H.
f([_|T], S) :- f(T, S1), S is S1.

g(H, S, S1):-
    H > 0,
    S1 < H,!,
    S is H.
g(_, S, S1):-
    S is S1.
f1([], 0).
f1([H|T], S):- f1(T,S1), g(H, S1, S).

f2([],[]).
f2([H|T], [H|S]):- f2(T, S).
f2([H|T], S):-H mod 2 =:= 0, f(T, S).

addtolist([], E, [E]).
addtolist([H|T], E, [E, H|T]).
addtolist([H|T], E, [H|TR]):- addtolist(T, E, TR).

perm([],[]).
perm([E|T],S):-perm(T,S1),
    select(E,S,S1).
prop([A,B]):-!,M is B-A,abs(M,R), R =<3.
prop([A,B|T]):-prop([B|T]),M is B-A,abs(M,R), R =<3.
oneSol(L,S):-perm(L,S),prop(S).
allSol(L,R):-findall(Re,oneSol(L,Re),R).

f3([], 0).
f3([H|T], S):-
    f3(T, S1),
    S1 is S-H.

%perm(l1..ln) = [], if n == 0
%               select(l1, S, perm(l2..ln))
perm2([], []).
perm2([E|T], S):-
    perm2(T, S1),
    select(E, S, S1).

%comb(l1..ln, k) = [], if k == 0
%                  l1 U comb(l2..ln, k-1), if k > 0
%                  comb(l2..ln, k), k > 0
comb(_, 0, []).
comb([H|T], K, [H|TR]):-
    K > 0,
    K1 is K - 1,
    comb(T, K1, TR).
comb([_|T], K, R):-
    K>0,
    comb(T, K, R).

%arr(l, k) = perm(comb(l, k))
arr(L, K, R):-
    comb(L, K, R1),
    perm(R1, R).

propArr([], 1).
propArr([H|T], P):- propArr(T, P1), P is P1*H.

oneArr(L, K, P, R):-
    arr(L, K, R),
    propArr(R, R1),
    R1 is P.

allArr(L, K, P, R):-
    findall(R1, oneArr(L, K, P, R1), R).

f4([], 0).
f4([H|T], S):-
    f4(T, S1),
    H < S1, !,
    S is H + S1.
f4([_|T], S):-
    f4(T, S1),
    S is S1 + 2.

%p(1). q(1). r(1).
%p(2). q(2). r(2).
%s :- !,
    %p(X),
    %q(Y),
    %r(Z),
    %write(X, Y, Z),
 %   nl.

subsets([], []).
subsets([H|T], [H|S]):- subsets(T, S).
subsets([_|T], S):- subsets(T, S).

subsetsSum([], 0):-!.
subsetsSum([H|T], S):- subsetsSum(T, S1), S is S1+H.
subsetsCond(L, R):-
    subsets(L, R),
    subsetsSum(R, Su),
    Su mod 3 =:= 0.
allSubsets(L, R):-
    findall(R1, subsetsCond(L, R1), R).


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

reverseHL([], []).
reverseHL([H|T], [R1|R]):-
    is_list(H),
    reverseHL(H, R1),
    reverseL(T, R).
reverseHL([_|T], R):-
    reverseHL(T, R).

subsets2([], []).
subsets2([H|T], [H|S]):-
    subsets2(T, S).
subsets2([_|T], S):-
    subsets2(T, S).
subsetsK([H|T], K, [R1|R]):-
    subsets2([H|T], R1),
    lengthL(R1, R2),
    R2 =:= K,
    subsetsK(T, K, R).

f5([], -1).
f5([H|T], S):- f(T, S1), S1>0, !, S is S1+H.
f5([_|T], S):- f(T, S1), S is S1.

exists([H|_], H):- !.
exists([_|T], H):- exists(T, H).

toSet([], []):- !.
toSet([H|T], S):-
    exists(T, H),
    toSet(T, S).
toSet([H|T], [H|S]):-
    toSet(T, S).

%toSet2(l1..ln, coll) = coll, if n = 0
%                       toSet2(l2..ln, [l1|coll]), if not exists (coll,
%                       l1)
%                       toSet2(l2..ln, coll), otherwise
toSet22([], Coll, Coll):- !.
toSet22([H|T], R):-
    not(exists(Coll, H)), !,
    Coll2 = [H|Coll],
    toSet22(T, Coll2, R).
toSet22([_|T], Coll, R):-
    toSet22(T, Coll, R).

subsets2([H|_], 1, [H]).
subsets2([H|T], N, [H|R]):-
    N > 1,
    N1 is N - 1,
    subsets2(T, N1, R).
subsets2([_|T], N, R):-
    subsets2(T, N, R).
allSubsets2(L, N, R):-
    findall(R1, subsets2(L, N, R1), R).

removeSecond([], _, _, []).
removeSecond([_|T], Pos1, Pos, R):-
    Pos1 =:= Pos,
    NewPos is Pos + 1,
    NewPos1 is Pos1 * 2,
    removeSecond(T, NewPos1, NewPos, R).
removeSecond([H|T], Pos1, Pos, [H|R]):-
    NewPos is Pos + 1,
    removeSecond(T, Pos1, NewPos, R).
