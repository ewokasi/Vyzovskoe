; 4 вариант к ((K L) (M N) A B C (D (E)))
;  4.1 элемент K
;  4.2 элемент M
;  4.3 элемент E
;  4.4 список (K D N)
;  4.5 список (A D K)
;  4.6 список (D (M N) A)

(write (caar '((K L) (M N) A B C (D (E)))))(terpri) ; k
(write (caadr '((K L) (M N) A B C (D (E)))))(terpri) ; m
(write (car(cadadr(cddddr '((K L) (M N) A B C (D (E)))))))(terpri)(terpri) ; (e)

; (K D N)
(write
  (cons (caar '((K L) (M N) A B C (D (E))))
  (cons (caadr(cddddr '((K L) (M N) A B C (D (E)))))
  (cons (cadadr '((K L) (M N) A B C (D (E))) ) nil)))
)(terpri)

; (A D K)
(write
  (cons (caddr '((K L) (M N) A B C (D (E))))
  (cons (caadr(cddddr '((K L) (M N) A B C (D (E)))))
  (cons (caar '((K L) (M N) A B C (D (E)))) nil)))
)(terpri)

; (D (M N) A)
(write
  (cons (caadr(cddddr '((K L) (M N) A B C (D (E)))))
  (cons (cadr '((K L) (M N) A B C (D (E))) )
  (cons (caddr '((K L) (M N) A B C (D (E)))) nil)))
)(terpri)