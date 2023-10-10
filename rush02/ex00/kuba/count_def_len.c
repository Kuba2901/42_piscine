int count_def_len(int file)
{
    int     start_counting;
    int     colon_found;
    int     def_len;
    char    buffer;

    start_counting = 0;
    def_len = 0;
    colon_found = 0;
    while (read(file, &buffer, 1) == 1) {
        if (buffer == '\n')
            break ;
        if (colon_found && buffer != ' ')
            start_counting++;
        if (colon_found && start_counting)
            def_len++;
        if (buffer == ':')
            colon_found++;
    }

    return def_len;
}