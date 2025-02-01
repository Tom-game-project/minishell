```c
typedef enum e_operator t_operator;
enum e_operator
{
	e_ope
	e_ope_redirect_i, // <
	e_ope_redirect_o, // >
	e_ope_heredoc_i,  // <<
	e_ope_heredoc_o,  // >>
	e_ope_and,        // &&
	e_ope_or          // || 
};

typedef struct s_ast t_ast

struct s_ast
{
	t_ast *next_ast;
	t_operator ope;
	t_ast *down_ast;
	char *cmd;
	char *argv;
};
```
```c
t_ast *ast

// echo $(ls -la | cat > outfile) | grep infile


// struct s_ast
// {
// 	t_ast *next_ast: 
// 		struct s_ast
// 		{
// 			t_ast *next_ast;
// 			t_operator ope; |
// 			t_ast *down_ast;	
// 			char *cmd; = grep
// 			char *argv; = infile
//         };
// 	t_operator ope;
// 	t_ast *down_ast;
// 		struct s_ast
// 		{
// 			t_ast *next_ast;
// 				struct s_ast
// 				{
// 					t_ast *next_ast;
// 					t_operator ope;
// 					t_ast *down_ast;
// 					char *cmd; = cat
// 					char *argv; = outfile
// 				};
// 			t_operator ope;
// 			t_ast *down_ast;
// 			char *cmd; ls
// 			char *argv; -la
//         };
// 	char *cmd; //= echo
// 	char *argv;
// };
```

```c
echo $(ls -la | cat > outfile) | grep infile

struct s_ast
{
	t_ast *next_ast: 
		struct s_ast
		{
			t_ast *next_ast;
			t_operator ope; 
			t_ast *down_ast;	
			char *cmd; grep
			char *argv; infile
        };
	t_operator ope; | 
	t_ast *down_ast;
		struct s_ast
		{
			t_ast *next_ast;
				struct s_ast
				{
					t_ast *next_ast; ls -la 
					t_operator ope; | 
					t_ast *down_ast;  cat > outfile
					char *cmd; NULL
					char *argv; NULL
				};
			t_operator ope;
			t_ast *down_ast;
			char *cmd; echo
			char *argv; NULL
        };
	char *cmd; //= NULL
	char *argv; // = NULL
};


fork_ope()
{
	int spawn_child()
	{
	fork
	pipe
	execve
	//再起
	waitpid
	return (exit_status);
	}
	spawn_child()
	t_operator ope;
}
```