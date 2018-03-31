/* this reducer cares about drawing boxes on a picture and nothing else */
let canvasMiddleware =
    (reducer: PipeTypes.reducer(CanvasTypes.action, CanvasTypes.state)) => {
  let (action: CanvasTypes.action, state: CanvasTypes.state) = reducer;
  switch (action) {
  | MouseUp(x, y) => {...state, endCoord: Some({x, y})}
  | MouseMove(x, y) => {...state, endCoord: Some({x, y})}
  | MouseDown(x, y) => {...state, startCoord: Some({x, y}), endCoord: None}
  };
};