# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strncpy.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:31:46 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:32:18 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_strncpy
	extern 		_ft_memcpy

_ft_strncpy:
	enter 		0, 0
	
	cmp 		rdi, 0x00
	je 			false
	
	cmp			rsi, 0x00
	je			false
	
	push 		rdi
	
	cmp			rdx, 0x00
	je			true
	
	mov			rcx, rdx

copy:
	cmp			byte [rsi], 0x00
	je			fill_zero
	
	mov 		al, [rsi]
	mov			[rdi], al
	
	inc			rdi
	inc			rsi
	
	loop		copy
	
	jmp true

fill_zero:
	mov			al, 0x00
	mov			[rdi], al
	
	inc			rdi
	
	loop		fill_zero

true:
	pop			rax
	leave
	ret

false:
	mov			 rax, 0x00
	leave
	ret
