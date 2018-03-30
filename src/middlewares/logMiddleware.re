/* stupidest possible middleware - does logging and returns the same */
let logMiddleware: Types.middleware(_, _) =
  reducer => {
    let (_, state) = reducer;
    Js.log2("LOG", state);
    state;
  };