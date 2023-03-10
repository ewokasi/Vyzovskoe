; 4. Разработать функцию, находящую теоретико-множественное пересечение
; двух списков.
; Например:
; Вход: (1 2 3 4 5), (4 5 6 7).
; Выход: (4 5).

(DEFUN checka (AT LST)
(COND
((NULL LST) NIL)
((EQL AT (CAR LST)) T)
(T (CHECKA AT (CDR LST)))
 ))


(defun inte (A B)

    (
        cond((null a)
            nil
        )
    )
    
    (
        cond((checka (car A) B)
            (write (car A))
            )
    )
    
    (inte (cdr A) B)
    
)

(write (inte '(1 2 3 4 ) '(3 4 5 6 7)))