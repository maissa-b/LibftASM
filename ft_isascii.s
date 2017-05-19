# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:08:38 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:15:52 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isascii

_ft_isascii:
	mov			rax, 0x01

	cmp			rdi, 0x00	
	jl			end
	
	cmp			rdi, 0x7f	
	jg			end
	
	ret

end:
	mov			rax, 0x00
	ret
