let logMiddleware: Types.middleware =
  reducer => {
    let (_, state) = reducer;
    Js.log2("LOG", state);
    state;
  };