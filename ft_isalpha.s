# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalpha.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:05:37 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:15:22 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isalpha

_ft_isalpha:
	cmp			rdi, 0x00	
	je			false
	
	cmp			rdi, 0x41	
	jl			false
	
	cmp			rdi, 0x5b	
	jl			true
	
	cmp			rdi, 0x61	
	jl			false
	
	cmp			rdi, 0x7b	
	jl			true
	
	jmp			false

true:
	mov			rax, 0x01	
	ret

false:
	mov			rax, 0x00	
	ret
