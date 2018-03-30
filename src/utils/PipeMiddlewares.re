/* Simple fold to run state through each middleware/reducer thing */
let runMiddlewares =
    (
      reducer: Types.reducer('a, 's),
      middlewares: list(Types.middleware('a, 's)),
    )
    : Types.reducer('a, 's) =>
  List.fold_right(
    (middleware, data) => {
      let (action, _) = data;
      let newState = middleware(data);
      (action, newState);
    },
    middlewares,
    reducer,
  );

/* do all middlewares then leave */
let pipeMiddlewares =
    (
      reducer: Types.reducer('a, 's),
      middlewares: list(Types.middleware('a, 's)),
    )
    : 's => {
  let piped = runMiddlewares(reducer, middlewares);
  let (_, state) = piped;
  state;
};

/* runs state through all passed middlewares and triggers state update */
let doReducer = (middlewares, action, state) =>
  ReasonReact.Update(pipeMiddlewares((action, state), middlewares));