# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:28:28 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:14:32 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_isalnum
	extern		_ft_isdigit
	extern		_ft_isalpha

_ft_isalnum:
	mov			rax, 0x00
	
	cmp			rdi, 0x00		
	je			end
	
	call		_ft_isdigit	
	cmp			rax, 0x01
	je			end
	
	call		_ft_isalpha	
	ret

end:
	ret
