
intersection([],_,[]). 
intersection([H|T],L2,[H|R]) :-
    member(H,L2),
    intersection(T,L2,R). 
intersection([H|T],L2,R) :- 
    not(member(H,L2)), 
    intersection(T,L2,R). 


remove_duplicates([],[]). 
remove_duplicates([H|T],[H|R]) :- 
    not(member(H,T)), 
    remove_duplicates(T,R). 
remove_duplicates([H|T],R) :- 
    member(H,T), 
    remove_duplicates(T,R). 


intersection_no_duplicates(L1,L2,R) :-
    intersection(L1,L2,I),
    remove_duplicates(I,R). 