# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memalloc.s                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/16 19:20:33 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:20:38 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
		
section .text
	global			_ft_memalloc
	extern			_ft_bzero
	extern			_malloc

_ft_memalloc:
	push			rsi
	push			rdi

	cmp				rdi, 0
	je				return_null

	;push			rsi
	;push			rdi

	call			_malloc

	cmp				rax, 0x00
	je				return_null

	pop				rsi
	mov				rdi, rax
	call			_ft_bzero

	mov				rdi, rsi
	pop				rsi
	
	ret

end:
	mov				rax, 0x00
	ret

return_null:
	pop				rdi
	pop				rsi
	
	mov				rax, 0x00
	ret
