/* 'a is action, 's is state */
type reducerInterface('a, 's) = {
  state: 's,
  send: 'a => unit,
};

/* 'a is action, 's is state */
type reducer('a, 's) = ('a, 's);

type middleware('a, 's) = reducer('a, 's) => 's;