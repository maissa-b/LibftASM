# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:26:56 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:27:03 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_memcpy

_ft_memcpy:
	enter			0, 0
	
	mov				rax, 0x00
	
	mov				rax, rdi
	mov				rcx, rdx

	cmp				rdi, 0x00
	je				end

	cmp				rsi, 0x00
	je				end
	
	rep				movsb

end:
	leave
	ret
