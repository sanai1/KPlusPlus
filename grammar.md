\<Program> ::= { \<GlobalStatement> }

\<GlobalStatement> ::= \<VarDeclaration> | \<Function>

\<VarDeclaration> ::= `var` \<Identifier> `:` \<Type> [`=` \<Expression>] `;` | `var` \<Identifier> `:` `Array` `<` \<Type> `>` `(` \<Expression> `)` `;`

\<Identifier> ::= \<Letter> | \<Letter>\<Number>

\<Type> ::= `Int` | `Boolean` | `Double` | `String` | `Array` `<` \<Type> `>`

\<Function> ::= `fun` \<Identifier> `(` [\<Parameters>] `)` `:` \<Type> \<Block>

\<Parameters> ::= \<Parameter> { `,` \<Parameter> }

\<Parameter> ::= \<Identifier> `:` \<Type>

\<Block> ::= `{` { \<Statement> } `}`

\<Statement> ::= \<VarDeclaration> | \<Assignment> | \<IfStatement> | \<WhenStatement> | \<WhileLoop> | \<ForLoop> | \<ReturnStatement> | \<Expression> `;`

\<Assignment> ::= \<Identifier> `=` \<Expression> `;` | \<ArrayAccess> `=` \<Expression> `;`

\<ArrayAccess> ::= \<Identifier> `[` \<Expression> `]`

\<ReturnStatement> ::= `return` \<Expression> `;`

\<IfStatement> ::= `if` `(` \<Expression> `)` \<Block> [`else` \<Block>]

\<WhenStatement> ::= `when` `(` <Expression> `)` `{` { \<CaseBlock> } [`default` `:` \<Block>] `}`

\<CaseBlock> ::= `case` <Expression> `:` \<Block>

\<WhileLoop> ::= `while` `(` \<Expression> `)` \<Block>

\<ForLoop> ::= `for` `(` \<Identifier> `in` \<Range> [`step` \<Number>] `)` \<Block> | `for` `(` \<Identifier> `in` \<Identifier> `)` \<Block>

\<Range> ::= \<Expression> `..` \<Expression>

\<Expression> ::= \<LogicalOr>

\<LogicalOr> ::= \<LogicalAnd> { `||` \<LogicalAnd> }

\<LogicalAnd> ::= \<Equality> { `&&` \<Equality> }

\<Equality> ::= \<Comparison> { (`==` | `!=`) \<Comparison> }

\<Comparison> ::= \<AddSub> { (`<` | `>` | `<=` | `>=`) \<AddSub> }

\<AddSub> ::= \<MulDiv> { (`+` | `-`) \<MulDiv> }

\<MulDiv> ::= \<Primary> { (`*` | `/`) \<Primary> }

\<Primary> ::= \<Number> | \<Boolean> | \<Identifier> | \<FunctionCall> | \<StringIndex> | \<StringProperty> | `(` \<Expression> `)`

\<FunctionCall> ::= \<Identifier> `(` [\<Arguments>] `)` | \<Identifier> `.` `substring` `(` \<Arguments> `)` | \<Identifier> `.` `length` `(` `)`

\<Arguments> ::= \<Expression> { `,` \<Expression> }

\<StringIndex> ::= \<Identifier> `[` \<Expression> `]`

\<StringProperty> ::= \<Identifier> `.` `length`

\<Letter> ::= `a` | `b` | `c` | `d` | `e` | `f` | `g` | `h` | `i` | `j` | `k` | `l` | `m` | `n` | `o` | `p` | `q` | `r` | `s` | `t` | `u` | `v` | `w` | `x` | `y` | `z` | `A` | `B` | `C` | `D` | `E` | `F` | `G` | `H` | `I` | `J` | `K` | `L` | `M` | `N` | `O` | `P` | `Q` | `R` | `S` | `T` | `U` | `V` | `W` | `X` | `Y` | `Z`

\<Number> ::= `0` | `1` | `2` | `3` | `4` | `5` | `6` | `7` | `8` | `9`

\<Boolean> ::= `true` | `false`