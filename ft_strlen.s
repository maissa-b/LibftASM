# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:33:19 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:33:36 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_strlen

_ft_strlen:
	cmp rdi, 0
	
	mov rax, 0
	je end
	
	mov rcx, -1
	
	cld
	repnz scasb
	
	not rcx
	dec rcx
	
	mov rax, rcx

end:
	ret
