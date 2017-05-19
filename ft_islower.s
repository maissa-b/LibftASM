# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:16:51 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:17:35 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_islower

_ft_islower:
	cmp				rdi, 0x0
	je				end
	
	cmp				rdi, 0x61
	jl				end
	
	cmp				rdi, 0x7a
	jg				end
	
	mov				rax, 0x01
	ret

end:
	mov				rax, 0x00
	ret
