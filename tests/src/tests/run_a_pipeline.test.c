#include "helpers.h"
#include "pipeline_runner.h"

int	test1(void);
int	test2(void);
int	test3(void);
int	test4(void);
int	test5(void);
int	test6(void);
int	test7(void);
int	test8(void);

int	main(void)
{
	run_a_test(test1, 1);
	run_a_test(test2, 2);
	run_a_test(test3, 3);
	run_a_test(test4, 4);
	run_a_test(test5, 5);
	run_a_test(test6, 6);
	run_a_test(test7, 7);
	run_a_test(test8, 8);
}

int	test1(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		ls | grep r | wc -l
	*/

	char *exe1 = "/bin/ls";
	char *args1[] = {exe1, NULL};
	char *exe2 = "/bin/grep";
	char *args2[] = {exe2, "r", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test2(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo Hello | cat
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "Hello", NULL};
	char *exe2 = "/bin/cat";
	char *args2[] = {exe2, NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test3(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "apple banana" | tr ' ' '\n' | wc -l
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "apple banana", NULL};
	char *exe2 = "/bin/tr";
	char *args2[] = {exe2, " ", "\n", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test4(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		ls | /bin/invalid_cmd | wc -l
	*/

	char *exe1 = "/bin/ls";
	char *args1[] = {exe1, NULL};
	char *exe2 = "/bin/invalid_cmd";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test5(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		printf "" | cat | wc -c
	*/

	char *exe1 = "/bin/printf";
	char *args1[] = {exe1, "", NULL};
	char *exe2 = "/bin/cat";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-c", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test6(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		cat /etc/passwd | grep root | wc -l
	*/

	char *exe1 = "/bin/cat";
	char *args1[] = {exe1, "/etc/passwd", NULL};
	char *exe2 = "/bin/grep";
	char *args2[] = {exe2, "root", NULL};
	char *exe3 = "/bin/wc";
	char *args3[] = {exe3, "-l", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test7(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "123 456" | sed 's/ /,/' | tr '1' '9' | cut -d',' -f2
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "123 456", NULL};
	char *exe2 = "/bin/sed";
	char *args2[] = {exe2, "s/ /,/", NULL};
	char *exe3 = "/bin/tr";
	char *args3[] = {exe3, "1", "9", NULL};
	char *exe4 = "/bin/cut";
	char *args4[] = {exe4, "-d", ",", "-f", "2", NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe4, args4, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}

int	test8(void)
{
	int result;
	t_pipeline *pipeline;

	/*
		/bin/echo "data" | /bin/false | cat
	*/

	char *exe1 = "/bin/echo";
	char *args1[] = {exe1, "data", NULL};
	char *exe2 = "/bin/false";
	char *args2[] = {exe2, NULL};
	char *exe3 = "/bin/cat";
	char *args3[] = {exe3, NULL};

	build_pipeline(&pipeline);

	add_to_list(pipeline->commands, create_command(exe1, args1, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe2, args2, NULL, NULL));
	add_to_list(pipeline->commands, create_command(exe3, args3, NULL, NULL));

	result = run_a_pipeline(pipeline);

	destroy_pipeline(&pipeline);
	return (result);
}
