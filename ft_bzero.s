# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:03:51 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:13:38 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_bzero

_ft_bzero:
	mov			rax, 0x00

	cmp			rdi, 0x00		
	je			end

	push		rdi
	push		rcx

	mov			rcx, rsi		

	rep			stosb

	pop			rcx
	pop			rdi

	mov			rax, rdi

end:
	ret
