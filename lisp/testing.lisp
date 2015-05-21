;;; testing.lisp

;; Triple value of a number
(defun triple (x)
  (* 3 x))

;; Negate sign of a number
(defun negate (x)
  (- x))

;; Calculate factorial of a number
(defun factorial (n)
  (if (= N 1)
	1
	(* N (factorial (- N 1)))))

;; Calculate nth fibonacci number
(defun fibonacci (n)
  (if (= n 1) 1
	(if (= n 2) 1
	  (+ (fibonacci (- n 1)) (fibonacci (- n 2))))))
