
typedef enum e_operator t_operator;
enum e_operator
{
	e_ope_redirect_i, // <
	e_ope_redirect_o, // >
	e_ope_heredoc_i,  // <<
	e_ope_heredoc_o,  // >>
	e_ope_and,        // &&
	e_ope_or          // ||
};

typedef struct ast t_ast

struct ast
{
	ast *t_ast;
	//必要なデータ
	//
	//
};
