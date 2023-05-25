
part(List, N, K, Take):-
   NK is N+K,
   length(Skip, N), append(Skip, Rest, List),
   length(Take, (K)), append(Take, _, Rest).

red(List, N, K, M, Res):-
    part(List, N,K, ToMove),
    part(List, 0, N, LeftPart),
    Right is N + K,
    length(List, Len),
    ToRight is Len - Right ,
    part(List, Right, ToRight, RightPart),

    append(LeftPart, RightPart, HalfPart),
    (M < K-> MoveIndex is M; MoveIndex is M-K ),
    
    part(HalfPart, 0, MoveIndex, LeftPart_Half),
    length(HalfPart, Len_h),
    
    Right_h is Len_h - MoveIndex,
    part(HalfPart, MoveIndex, Right_h, RightPart_Half),
    
    append(LeftPart_Half, ToMove, ToMove_temp),
    append(ToMove_temp, RightPart_Half, Res).