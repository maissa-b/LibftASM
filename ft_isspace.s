# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isspace.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:18:12 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:19:05 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


section .text
	global			_ft_isspace

_ft_isspace:
	cmp				rdi, 0x00
	je				false
	
	cmp				rdi, 0x09
	jl				false
	
	cmp				rdi, 0x0d
	jle				true
	
	cmp				rdi, 0x20
	jne				false

true:
	mov				rax, 0x01
	ret

false:
	mov				rax, 0x00
	ret
