# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:27:12 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:27:20 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_memset

_ft_memset:
	enter			0, 0
	
	mov				rax, 0x00
	
	cmp				rdi, 0x00
	je				end
	
boucle:
	mov				rcx, rdx
	mov				rbx, rdi
	mov				rax, rsi
	
	rep				stosb
	
	mov				rax, rbx

end:
	leave
	ret
