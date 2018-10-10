#ifndef U_CONFIG_H
#define U_CONFIG_H

#ifndef _FILE_DEFINED
#define _FILE_DEFINED
typedef struct _iobuf
{
    void* _Placeholder;
} FILE;
#endif /* _FILE_DEFINED */

class u_config {
    const char *_path;
    FILE       *_fd;
public:
    u_config(const char *path);
    ~u_config(void);
    bool           exists(void);
    void           open_config(const char *mode);
    void           close_config(void);
    void           write_config(void *buffer, size_t length);
    int            GetInt(const char *name);
    float          GetFloat(const char *name);
private:
    bool           SetPos(const char *name);
    bool           GetVal(const char *name, char buffer[32]);
} ;

#endif /* U_CONFIG_H */

