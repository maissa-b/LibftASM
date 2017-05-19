# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isxdigit.s                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:06:22 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/08 19:08:28 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isxdigit
	extern		_ft_isdigit
	extern		_ft_isascii

_ft_isxdigit:
	cmp			rdi, 0x00
	je			false

	call		_ft_isdigit
	cmp			rax, 0x01
	je			true

	call		_ft_isascii
	cmp			rax, 0x01
	jne			false

	cmp			rdi, 0x41
	jl			false

	cmp			rdi, 0x47
	jl			true
	
	cmp			rdi, 0x61
	jl			false
	
	cmp			rdi, 0x67
	jl			true
	
	jmp			false

true:
	mov			rax, 0x01
	ret

false:
	mov			rax, 0x00
	ret
