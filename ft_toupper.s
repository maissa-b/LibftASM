# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:34:52 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:39:15 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_toupper
	extern			_ft_islower

_ft_toupper:
	push			rdi

	cmp				rdi, 0x00
	je				false
	
	call			_ft_islower
	
	cmp				rax, 0x01
	jne				false

true:
	pop				rax
	sub				rax, 32
	ret

false:
	pop				rax
	ret
