function populate(command, word, cache) {
    var ops = command.split("->");
    var target = ops[1].trim();
    var expression = ops[0].trim();

    if (isNaN(expression))
        world[target] = expression;
    else
        world[target] = expression * 1;
    cache[target] = NaN;
}
