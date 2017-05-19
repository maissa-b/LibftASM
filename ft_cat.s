# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maissa-b <maissa-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/08 19:31:20 by maissa-b          #+#    #+#              #
#    Updated: 2015/05/16 19:14:02 by maissa-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section	.data
	buffer		times 255 db 0
	buffsize	equ $ - buffer

section	.text
	global		_ft_cat
	extern		_ft_strlen

_ft_cat:
	enter		0, 0

read:								
	mov			rax, 0x2000003		
	push		rdi					
	lea			rsi, [rel buffer]	
	mov			rdx, buffsize		
	syscall							
	
	jc			error
	cmp			rax, 0x00			
	je			end
	mov			rdi, 0x01			
	mov			rdx, rax			
	mov			rax, 0x2000004	
	syscall							
	
	jc			error
	pop			rdi
	jmp			read

error:
	pop			rdi
	mov			rax, 0x01

end:
	leave
	ret
