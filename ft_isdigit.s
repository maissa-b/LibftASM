# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:04:53 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:16:41 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isdigit

_ft_isdigit:
	mov			rax, 0x01
	cmp			rdi, 0x00	
	je			false
	
	cmp			rdi, 0x30
	jl			false
	
	cmp			rdi, 0x39
	jg			false
	
	ret

false:
	mov			rax, 0x00
	ret
