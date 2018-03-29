let runMiddlewares =
    (reducer: Types.reducer, middlewares: list(Types.middleware))
    : Types.reducer =>
  List.fold_right(
    (middleware, data) => {
      let (action, _) = data;
      let newState = middleware(data);
      (action, newState);
    },
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