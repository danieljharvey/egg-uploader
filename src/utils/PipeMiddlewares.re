let runMiddlewares =
    (reducer: Types.reducer, middlewares: list(Types.middleware))
    : Types.reducer =>
  List.fold_right(
    (middleware, data) => middleware(data),
    middlewares,
    reducer,
  );

let pipeMiddlewares =
    (reducer: Types.reducer, middlewares: list(Types.middleware))
    : Types.state => {
  let piped = runMiddlewares(reducer, middlewares);
  let (_, state) = piped;
  state;
};