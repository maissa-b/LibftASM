# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:10:59 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:18:00 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isprint

_ft_isprint:
	mov			rax, 0x01
	
	cmp			rdi, 0x20	
	jl			end
	
	cmp			rdi, 0x7e
	jg			end
	
	ret

end:
	mov			rax, 0x00
	ret
