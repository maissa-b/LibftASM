# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:33:52 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:40:08 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_tolower
	extern			_ft_isupper	

_ft_tolower:
	push			rdi

	cmp				rdi, 0x00
	je				false
	
	call			_ft_isupper
	
	cmp				rax, 0x01
	jne				false

true:
	pop				rax
	add				rax, 32
	ret

false:
	pop				rax
	ret
