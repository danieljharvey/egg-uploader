/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | MouseDown(int, int)
  | MouseMove(int, int)
  | MouseUp(int, int);

type reducerInterface = {
  state,
  send: action => unit,
};

type reducer = (action, state);

type middleware = reducer => reducer;