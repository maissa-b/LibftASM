# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:19:14 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:19:49 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global			_ft_isupper

_ft_isupper:
	cmp				rdi, 0x00
	je				end
	
	cmp				rdi, 0x41
	jl				end
	
	cmp				rdi, 0x5a
	jg				end
	
	mov				rax, 0x01
	ret

end:
	mov				rax, 0x00
	ret
