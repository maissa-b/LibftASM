# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:29:38 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:31:39 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_strcpy
	extern			_ft_strlen

_ft_strcpy:
	enter			0, 0
	
	push			rdi
	
	cmp				rdi, 0x00
	je				end
	
	mov				r15, rdi
	mov				rdi, rsi
	
	call			_ft_strlen
	mov				rcx, rax
	mov				rdi, r15
	
	rep				movsb
	
	mov				byte [rdi], 0x00

end:
	pop				rax
	leave
	ret
