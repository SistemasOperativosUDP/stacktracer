.global get_ebp
.global get_next_ebp
.global get_int_value
.global get_char_value
.global get_float_value
.global get_double_value
.global get_string_value
.global get_void_value
.global get_string_array_value
.global get_function_return

get_ebp:
	movl %ebp, %eax
	ret
get_next_ebp:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx,%eax
	ret
get_int_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	movl (%ebx,%eax),%ecx
	movl %ecx,%eax
	ret
get_char_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	movl (%ebx,%eax),%ecx
	movl %ecx,%eax
	ret
get_float_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	flds (%ebx,%eax)
	ret
get_double_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	fldl (%ebx,%eax)
	ret
get_string_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	movl (%ebx,%eax),%ecx
	movl %ecx,%eax
	ret
get_void_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	movl (%ebx,%eax),%ecx
	movl %ecx,%eax
	ret
get_string_array_value:
	movl 4(%esp),%eax
	movl 0(%eax),%ebx
	movl %ebx, %eax
	movl 8(%esp), %ebx
	movl (%ebx,%eax),%ecx
	movl %ecx,%eax
	ret
get_function_return:
	movl 4(%esp),%eax
	movl 4(%eax),%ebx
	movl %ebx,%eax
	ret

