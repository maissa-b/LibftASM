# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_putstring.s                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:27:47 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:28:02 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .data
	null		db "(null)"

section .text
	global		_ft_putstring
	extern		_ft_strlen

_ft_putstring:
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
	jmp			end

put_null:
	mov			rax, 0x2000004
	mov			rdi, 1
	lea			rsi, [rel null]
	mov			rdx, 6
	syscall
	jc			error
	jmp			end

error:
	mov			rax, -1
	ret

end:
	ret
