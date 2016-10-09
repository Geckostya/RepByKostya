class Scope:
    def __init__(self, parent=None):
        self.MyDict = {}
        self.parent = parent

    def __getitem__(self, key):
        if key in self.MyDict:
            return self.MyDict[key]
        elif self.parent is not None:
            return self.parent[key]
        else:
            return Number(42)

    def __setitem__(self, key, value):
        self.MyDict[key] = value


class Number:
    def __init__(self, value):
        self.value = value

    def evaluate(self, scope):
        return self


class Function:
    def __init__(self, args, body):
        self.args = args
        self.body = body

    def __call__(self, scope):
        return self

    def evaluate(self, scope):
        cur_limb = self
        for limb in self.body:
            cur_limb = limb.evaluate(scope)
        return cur_limb


class FunctionDefinition:
    def __init__(self, name, function):
        self.name = name
        self.function = function

    def __call__(self, scope):
        return self.evaluate(scope)

    def evaluate(self, scope):
        scope[self.name] = self.function
        return self.function


class FunctionCall:
    def __init__(self, fun_expr, args):
        self.fun_expr = fun_expr
        self.args = args

    def evaluate(self, scope):
        function = self.fun_expr(scope)
        call_scope = Scope(scope)
        for arg, key in zip(self.args, function.args):
            call_scope[key] = arg.evaluate(call_scope)
        return function.evaluate(call_scope)


class Conditional:
    def __init__(self, condition, if_true, if_false=None):
        self.condition = condition
        self.if_true = if_true
        self.if_false = if_false

    def evaluate(self, scope):
        condition = self.condition.evaluate(scope).value
        do_eval = Number(42)
        if condition:
            to_do = self.if_true
        else:
            to_do = self.if_false
        for do in to_do or []:
            do_eval = do.evaluate(scope)
        return do_eval


class Print:
    def __init__(self, expr):
        self.expr = expr

    def evaluate(self, scope):
        self.value = self.expr.evaluate(scope)
        print(int(self.value.value))
        return self.value


class Read:
    def __init__(self, name):
        self.name = name

    def evaluate(self, scope):
        scope[self.name] = Number(int(input()))
        return scope[self.name]


class Reference:
    def __init__(self, name):
        self.name = name

    def evaluate(self, scope):
        return scope[self.name]


BinaryDict = {
    "+": lambda x, y: x+y,
    "-": lambda x, y: x-y,
    "*": lambda x, y: x*y,
    "/": lambda x, y: x//y,
    "%": lambda x, y: x % y,
    "==": lambda x, y: int(x == y),
    "!=": lambda x, y: (x != y),
    "<": lambda x, y: int(x < y),
    ">": lambda x, y: int(x > y),
    "<=": lambda x, y: int(x <= y),
    ">=": lambda x, y: int(x >= y),
    "&&": lambda x, y: int(x and y),
    "||": lambda x, y: int(x or y)
}


class BinaryOperation:
    def __init__(self, lhs, op, rhs):
        self.op = op
        self.lhs = lhs
        self.rhs = rhs

    def evaluate(self, scope):
        lhs = self.lhs.evaluate(scope).value
        rhs = self.rhs.evaluate(scope).value
        self.value = Number(BinaryDict[self.op](lhs, rhs))
        return self.value


UnaryDict = {"-": lambda x: -x, "!": lambda x: not x}


class UnaryOperation:
    def __init__(self, op, expr):
        self.op = op
        self.expr = expr

    def evaluate(self, scope):
        self.value = Number(UnaryDict[self.op](self.expr.evaluate(scope).value))
        return self.value


def example():
    parent = Scope()
    parent["foo"] = Function(('hello', 'world'),
                             [Print(BinaryOperation(Reference('hello'),
                                                    '+',
                                                    Reference('world')))])
    parent["bar"] = Number(10)
    scope = Scope(parent)
    assert 10 == scope["bar"].value
    scope["bar"] = Number(20)
    assert scope["bar"].value == 20
    print('It should print 2: ', end=' ')
    FunctionCall(FunctionDefinition('foo', parent['foo']),
        [Number(5), UnaryOperation('-', Number(3))]).evaluate(scope)


def my_tests():
    print("start test")
    program = FunctionCall(Function( ('a') , [Print(Reference('a'))]), [Number(10)])
    program.evaluate(Scope())
    s1 = Scope()
    s1["num1"] = Number(2)
    s1["num2"] = Number(4)
    s2 = Scope(s1)
    s2["num1"] = Number(6)
    s2["pr1"] = Print(s2['num1'])
    s2["pr1"].evaluate(s2)
    print("write num")
    Read("num3").evaluate(s1)
    s1["num3"] = UnaryOperation("-",
                                BinaryOperation(s1["num2"], "/", s1["num3"]).evaluate(s1)
                               ).evaluate(s1)
    s2["pr1"] = Print(s2["num3"])
    s2["pr1"].evaluate(s2)
    s1["num1"] = BinaryOperation(s1["num1"], "==", s1["num3"]).evaluate(s1)
    print ("num1: ", end='')
    Print(s1["num1"]).evaluate(s1)
    Conditional(s1["num1"],
                [Print(BinaryOperation(s1["num2"], "*", Number(7000)))],
                [Print(UnaryOperation("!", Number(0)))]
               ).evaluate(s2)
    print("end test")

if __name__ == '__main__':
    example()
    my_tests()
