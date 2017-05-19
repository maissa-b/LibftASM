# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_puts.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:27:31 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:27:39 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .data
	null		db "(null)", 10

section .text
	global		_ft_puts
	extern		_ft_strlen

_ft_puts:
	cmp			rdi, 0
	je			put_null
	
print:
	push		rdi
	call		_ft_strlen
	mov			rdx, rax
	pop			rsi
	mov			rdi, 1
	mov			rax, 0x2000004
	syscall
	jc			error

put_nl:
	mov			rax, 0x2000004
	mov			rdi, 1
	lea			rsi, [rel new_line]
	mov			rdx, 1
	syscall
	jc			error
	jmp			finish

put_null:
	mov			rax, 0x2000004
	mov			rdi, 1
	lea			rsi, [rel null]
	mov			rdx, 7
	syscall
	jc			error
	jmp			finish

new_line:
	db			10

error:
	mov			rax, -1
	ret

finish:
	ret
