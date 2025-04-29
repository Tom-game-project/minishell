#ifndef ERR_MSG_H
#define ERR_MSG_H

void print_error_format_string(char *cmd, char *msg);


int	report_command_not_found(char *cmd);

int	report_is_a_directory(char *cmd);

int	report_no_such_file_or_directory(char *cmd);

int	report_permission_denied(char *cmd);

#endif

