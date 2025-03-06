#include "helpers.h"
#include "pipeline_runner.h"


int	test1(void);
int	test2(void);

int	main(void)
{
	run_a_test(test1, 1);
	// run_a_test(test2, 2);
}

int	test1(void)
{
	int result;
	t_pipeline *pipeline;

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
