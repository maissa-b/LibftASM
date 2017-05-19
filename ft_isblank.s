# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isblank.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:39:14 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:16:12 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text	
	global 		_ft_isblank

_ft_isblank:
	cmp			rdi, 0x09	
	je			true
	
	cmp			rdi, 0x20	
	je			true

false:
	mov			rax, 0x00
	ret

true:
	mov			rax, 0x01
	ret
