; Ryan Grayson
; rtg5xkh
; PreLab 9			
; threexplusone.s
; 4/14/2021
; *Note: This is for macOS. For linux compilation, the _ before threexplusone needs to be removed
	
;;OPTIMIZATIONS:
;; 1. replaced idiv instruction with shr to compute x /= 2 more quickly (in even:)
;; 2. replaced imul instruction with shl to compute x *= 3 more quickly (in odd:)
;; 3. replaced idiv instructions with logical and to check x % 2 more quickly (lines 20-22)
	
	global _threexplusone

	section .text

_threexplusone:
	;; return number of steps in collatz conjecture for int x (rdi) | rsi is 2nd arg to store num of steps
	cmp	rdi, 1		;does x == 1?
	je	done		;if so, goto done

	mov	r10, rdi	;r10 = x
	and	r10, 0x01	;if x is even, r10 = 0, if x is odd, r10 = 1
	cmp	r10, 1		;does r10 == 1?
	je	odd		;if so, odd case
	jmp	even		;else even case

odd:	
	mov	r11, rdi	;
	shl	rdi, 1		;x = 3*x + 1
	add	rdi, r11	;
	inc	rdi		;
	inc	rsi		;steps++
	call	_threexplusone	;recursive call
	jmp	done		;goto done after everything finishes

even:
	shr	rdi, 1		;x /= 2
	inc	rsi		;steps++
	call 	_threexplusone	;recursive call
	jmp	done		;goto done after everything finishes
	
done:
	mov	rax, rsi
	ret
