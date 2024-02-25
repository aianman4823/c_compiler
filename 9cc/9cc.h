typedef enum
{
  ND_ADD, //+
  ND_SUB, //-
  ND_MUL, //*
  ND_DIV, // /
  ND_EQ,  // ==
  ND_NE,  // !=
  ND_LT,  // <
  ND_LE,  // <=
  ND_NUM, // 整数
} NodeKind;

typedef struct Node Node;

struct Node
{
  NodeKind kind; // ノードの種類
  Node *lhs;     // 左辺のノード
  Node *rhs;     // 右辺のノード
  int val;       // kindがND_NUMの場合のみ使う
};

// トークンの種類
typedef enum
{
  TK_RESERVED, // 記号
  TK_NUM,      // 整数トークン
  TK_EOF       // 入力の終わりを表すトークン
} TokenKind;

typedef struct Token Token;

struct Token
{
  TokenKind kind;
  Token *next;
  int val;
  char *str;
  int len;
};

extern Node *expr(void);
extern Token *tokenize(char *p);

extern void gen(Node *node);

extern char *user_input;
extern Token *token;

extern void error_at(char *loc, char *fmt, ...);
extern void error(char *fmt, ...);