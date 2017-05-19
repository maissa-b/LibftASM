# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strnew.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:03:38 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:33:45 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global		_ft_strnew
	extern		_ft_memalloc

_ft_strnew:
	mov			rax, 0x00

	push		rdi

	inc			rdi

	call		_ft_memalloc

	pop			rdi

end:
	ret
